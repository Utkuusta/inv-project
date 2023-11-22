#!/bin/bash

# Extract command-line arguments
ssid="$1"
psk="$2"
# Set Wi-Fi network

# Run the scan command
WPA_CLI_PATH="/usr/sbin/wpa_cli"
$WPA_CLI_PATH -i wlan0 <<EOF > /dev/null 2>&1
add_network
set_network 0 ssid "$ssid"
set_network 0 psk "$psk"
enable_network 0
save_config
quit
EOF
