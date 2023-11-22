#!/bin/bash

# Scan Wi-Fi networks

# Run the scan command
WPA_CLI_PATH="/usr/sbin/wpa_cli"
$WPA_CLI_PATH -i wlan0 <<EOF > /dev/null 2>&1
scan
quit
EOF

# Wait for one second to allow finding networks
sleep 1

# Now continue with other commands
SCAN_RESULTS=$($WPA_CLI_PATH -i wlan0 <<EOF
scan_results
EOF
)

$WPA_CLI_PATH -i wlan0 <<EOF > /dev/null 2>&1
quit
EOF

echo "$SCAN_RESULTS" > scan_results.txt
