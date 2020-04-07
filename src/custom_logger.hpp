/**
 * @file custom_logger.hpp
 *
 * @brief Custom logger class
 *
 * @author Sergio Boatella Ojeda
 * Contact: sergioboatella@gmail.com
 *
 */

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>

namespace custom_logger {

    // Utility to convert a number to HEX representation
    template < class T > std::string to_hex(const T & number) {
        std::stringstream ss;
        ss << std::hex << number;
        return ss.str();
    }
    
    // Code snippet to get current time stamp in year/mo/dy hr:mn:sc.xxxxxx format
    std::string timestamp() {
        //get the time
        std::chrono::system_clock::time_point tp = std::chrono::system_clock::now();
        
        std::time_t tt = std::chrono::system_clock::to_time_t(tp);
        std::tm gmt {};
        gmtime_r(&tt, &gmt);

        std::chrono::duration < double >fractional_seconds =
            (tp - std::chrono::system_clock::from_time_t(tt)) + std::chrono::seconds(gmt.tm_sec);

        //format the string
        std::string buffer("year/mo/dy hr:mn:sc.xxxxxx");

        sprintf(&buffer.front(), "%04d-%02d-%02d %02d:%02d:%09.6f", gmt.tm_year + 1900, gmt.tm_mon + 1,
                gmt.tm_mday, gmt.tm_hour, gmt.tm_min, fractional_seconds.count());

        return buffer;
    }

// Custom logger class for basic logging functionallity using singleton pattern
    class Logger {

 public:
        static Logger & getInstance() {
            static Logger instance;
             return instance;

        }
 private:

         Logger() {
        }

        // Only write on file if logfile is set
        std::string logfile;

        bool logfileSet = false;

        // Actual output
        template < class T > void write_out(const std::string & label, const T & msg) {
            std::stringstream ss;
            ss << timestamp();
            ss << "::" << label << "::" << msg << std::endl;
            if (logfileSet) {
                std::ofstream log_file(logfile, std::ios_base::out | std::ios_base::app);
                log_file << ss.str();
            }
            std::cout << ss.str();
        }

 public:
        Logger(Logger const &) = delete;
        void operator=(Logger const &) = delete;

        virtual ~ Logger() {
            if (logfileSet)
                std::cout << "Execution log saved in " << getLogfile() << std::endl;
        }

        template < class T > void info(const T & msg) {
            write_out("INFO", msg);
        }

        template < class T > void warn(const T & msg) {
            write_out("WARN", msg);
        }

        template < class T > void error(const T & msg) {
            write_out("ERROR", msg);
        }

        template < class T > void debug(const T & msg) {
#ifdef DEBUG
            write_out("DEBUG", msg);
#endif
        }

        // SETTER
        void setLogfile(const std::string & filename) {
            logfile = filename;
            logfileSet = true;
        }

        // GETTER
        std::string getLogfile()const {
            return logfile;
        }
    };
};

#endif                          // LOGGER_H
