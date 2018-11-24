# protonhax
Tool to help running other programs (i.e. Cheat Engine) inside Steam's proton.

## Usage
In Steam set the launch options for the desired game to `protonhax init %COMMAND%`

To list all running appids use\
`protonhax ls`

To run a program with proton use\
`protonhax run <appid> <path/to/program> [args...]`\
NOTE: The PATH variable is ignored

To run cmd.exe use\
`protonhax cmd <appid>`

To run a program natively with the environment variables that were used to launch the game originally use\
`protonhax exec <appid> <path/to/program> [args...]`\
NOTE: The PATH variable is ignored

## Installing
### Arch Linux
- https://aur.archlinux.org/packages/protonhax/

## Contributing
Contributions are always welcome! Especially if they are packages for other distributions.
