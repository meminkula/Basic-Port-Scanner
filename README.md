# C-Based Basic Port Scanner

This project is designed to find and detect open TCP ports on devices within your local network.

## Features

* Network Discovery: Integrated `arp-scan` to list active devices in your local network.


* Scan Modes:        * Single port scanning for specific targets.
                     * Range scanning (1-1024) for comprehensive analysis.


* Low-Level Development: Built using pure C and Linux Socket API.

## Setup and Run

You must have `arp-scan` and `gcc` installed on your system.

To install dependencies:
```bash
sudo apt update
sudo apt install arp-scan gcc -y ```

To compile and run:

    Open your terminal in the project directory.

    Compile the code:
    
    ```gcc scanner.c -o scanner```
    
    Run with sudo privileges(it required for arp-scan and raw sockets):
    
    ```chmod +x scanner
    
       sudo ./scanner```
    
    
