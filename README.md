
# Cattie
A Linux utility to view file content

# Installing Cattie

1. Clone the repository 
	`git clonehttps://github.com/tanveerraza789/Cattie.git`
2. Open the repository 
	`cd Cattie`
3. Change file permission to enable execution
	`chmod +x install.sh uninstall.sh`
4. Run `sh install.sh` to install.
5. Run `sh uninstall.sh` to uninstall.
6. To build in to local folder run `make` or `make run` to run after building.

# Usage

## Usage Example
	cattie -l=50 -r filename.txt
Expected output : Content of the file up to 50 lines or end of file whichever triggers before.
## Flags


|Flag |Usage  | Working|
--- | --- | ---
|l|`-l=10`|Number of lines to be displayed|
|r|`-r`|View file from last|
|h|`-h`|View the help message|
