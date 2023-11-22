#!/bin/bash

WPA_CLI_PATH="/usr/sbin/wpa_cli"

# Run wpa_cli to remove all networks
$WPA_CLI_PATH -i wlan0 <<EOF > /dev/null 2>&1
remove_network 0
save_config
EOF
