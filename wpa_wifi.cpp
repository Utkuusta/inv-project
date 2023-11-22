#include "wpa_wifi.h" // Include the header file
#include <stdio.h>
#include <cstdlib>  // For the system function
#include <string.h>

///Opens wpa_cli, scan, waits 1 sec, then scan_results
int scanresults() {

    // Assuming test.sh is in the working directory
    const char *command = "./scripts/scanresults.sh";

    // Execute the shell script
    int result = system(command);

    // Check if the command executed successfully
    if (result == 0) {
        // Success
        // Read scan results from file
        FILE *file = fopen("scan_results.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char buffer[1023];
    int print = 0;

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, "bssid / frequency / signal level / flags / ssid") != NULL) {
            print = 1;
            continue;  // Skip the header line
        }

        if (print) {
            // Process each line of scan results
            printf("%s", buffer);

            if (strstr(buffer, "quit") != NULL) {
                // Stop printing when "quit" is found
                break;
            }
        }
    }

    fclose(file);

        return 0;
    } else {
        // An error occurred
        return 1;
    }

    
}


int setnetwork() {

    const char *command = "./scripts/setnetwork.sh";

    // Two string values to pass
    char value1[100];
    char value2[100];

    // Read strings using scanf
    printf("Enter ssid: ");
    scanf("%99s", value1);  // Limiting to 99 characters to avoid buffer overflow
    printf("Enter psk: ");
    scanf("%99s", value2);  // Limiting to 99 characters to avoid buffer overflow

    // Construct the command with arguments
    char fullCommand[256];
    snprintf(fullCommand, sizeof(fullCommand), "%s \"%s\" \"%s\"", command, value1, value2);

    // Execute the shell script
    int result = system(fullCommand);

    return result;
    
}


int removenetwork() {

    // Assuming test.sh is in the working directory
    const char *command = "./scripts/removenetwork.sh";

    // Execute the shell script
    int result = system(command);

    // Check if the command executed successfully
    if (result == 0) {
        // Success
        return 0;
    } else {
        // An error occurred
        return 1;
    }

    
}