#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

bool show_file_content(const char *filename, uint64_t length = 0, bool reverse = false)
{
    uint64_t total_lines = 0;
    std::ifstream ipfile(filename);
    if (!ipfile or !ipfile.is_open())
    {
        printf(" :: File not found or unable to read!\n");
        return false;
    }
    total_lines = std::count(std::istreambuf_iterator<char>(ipfile),
                             std::istreambuf_iterator<char>(), '\n');
    if (length == 0)
            length = total_lines;
    ipfile.seekg(0,std::ios::beg);
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
    return true;
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

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf(" :: Inappropriate command line usage\n");
        show_help();
        return 0;
    }

    uint64_t length = 0;
    bool reverse = false;
    const char *filename = nullptr;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            if (argv[i][1] == 'l')
            {
                if (strlen(argv[i]) < 4)
                {
                    printf(" :: Inappropriate command line usage\n");
                    show_help();
                    return 0;
                }
                else
                {
                    char len[10];
                    strcpy(len, argv[i] + 3);
                    for (size_t j = 0; j < strlen(len); j++)
                    {
                        if (!isdigit(len[j]))
                        {
                            printf(" :: Inappropriate command line usage\n");
                            show_help();
                            return 0;
                        }
                    }
                    length = atoi(len);
                }
            }
            else if (argv[i][1] == 'r')
            {
                reverse = true;
            }
            else if (argv[i][1] == 'h')
            {
                show_help();
                return 0;
            }
        }
        else
        {
            if (filename == nullptr)
            {
                filename = argv[i];
            }
            else
            {
                printf(" :: Multiple files are not supported\n");
                show_help();
                return 0;
            }
        }
    }
    show_file_content(filename, length, reverse);
    return 0;
}
