#include <getopt.h>

#include "errorcodes.h"
#include "cattie.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf(" :: Inappropriate command line usage\n");
        show_help();
        return INAPPROPRIATE_CMD_USE;
    }
    bool reverse = false;
    int length = 0;
    char *filename = nullptr;
    int flag;
    while ((flag = getopt(argc, argv, ":hrl:")) != -1)
    {
        switch (flag)
        {
        case 'r':
            reverse = true;
            break;
        case 'l':
            char len[10];
            strcpy(len, optarg);
            for (size_t j = 0; j < strlen(len); j++)
            {
                if (!isdigit(len[j]))
                {
                    printf(" :: Inappropriate command line usage\n");
                    show_help();
                    return INAPPROPRIATE_CMD_USE;
                }
            }
            length = atoi(len);
            break;
        case 'h':
            show_help();
            return 0;
            break;
        case ':':
            printf(" :: Inappropriate command line usage\n");
            show_help();
            return INAPPROPRIATE_CMD_USE;
        case '?':
            printf(" :: Unknown option : %c\n", optopt);
            return UNKNOWN_OPTION;
            break;
        }
    }
    for (; optind < argc; optind++)
    {
        if (filename == nullptr)
        {
            filename = argv[optind];
        }
        else
        {
            printf(" :: Multiple files are not supported\n");
            show_help();
            return MULTI_FILE_ERR;
        }
    }
    return cattie(filename, length, reverse);
    return 0;
}
