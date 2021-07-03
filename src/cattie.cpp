#include "cattie.h"
#include "errorcodes.h"

int cattie(const char *filename, uint64_t length = 0, bool reverse = false)
{
    uint64_t total_lines = 0;
    std::ifstream ipfile(filename);
    if (!ipfile or !ipfile.is_open())
    {
        printf(" :: File not found or unable to read!\n");
        return FILE_NOT_FOUND;
    }
    total_lines = std::count(std::istreambuf_iterator<char>(ipfile),
                             std::istreambuf_iterator<char>(), '\n');
    if (length == 0)
        length = total_lines;
    else
        length = std::min(total_lines, length);
    ipfile.seekg(0, std::ios::beg);
    if (reverse)
    {
        uint64_t leave_lines = total_lines - length;
        std::string temp_reader;
        for (size_t i = 0; i < leave_lines; i++)
            getline(ipfile, temp_reader);
        while (ipfile)
        {
            temp_reader.erase();
            getline(ipfile, temp_reader);
            std::cout << temp_reader << std::endl;
        }
    }
    else
    {
        while (ipfile and length--)
        {
            std::string line;
            getline(ipfile, line);
            std::cout << line << std::endl;
        }
    }
    ipfile.close();
    return 0;
}

void show_help()
{
    std::string help_msg{"Cattie    : A utility to display text files in terminal\n"};
    help_msg += "Usage     : cattie -l=50 -r filename.txt\n";
    help_msg += "Flags :\n";
    help_msg += ":: -l=length : number of lines to be displayed on terminal\n";
    help_msg += "             : length should be a positive integer\n";
    help_msg += ":: -r        : Show file content from the last\n";
    help_msg += ":: -h        : Show this help message\n";
    std::cout << help_msg << std::endl;
}
