# protonhax

Tool to help running other programs (i.e. Cheat Engine) inside Steam's proton.

## Usage
Set the steam game launch options to `protonhax init %COMMAND%`

On your Steam Library:
- Right-click the game > Properties > General.
- Set Launch Options as `protonhax init %COMMAND%`.

Now, you can use your terminal to run the following commands:

- To list all running appids use\
`protonhax ls`

- To run a program with proton use\
`protonhax run <appid> <path/to/program> [args...]`\
NOTE: The PATH variable is ignored

- To run cmd.exe use\
`protonhax cmd <appid>`

- To run a program natively with the environment variables that were used to launch the game originally use\
`protonhax exec <appid> <path/to/program> [args...]`\
NOTE: The PATH variable is ignored

## Installing

**protonhax** is currently a single bash script, you just need to add it to your $PATH. 

1. Either clone our repo `https://github.com/jcnils/protonhax.git`, or download the source from our [release page](https://github.com/jcnils/protonhax/releases)
2. Copy the **protonhax** file to where you preffer and give it permission to execute:
    - Example of locations `$HOME/.local/bin/protonhax`, `/usr/bin/protonhax`. They need to be on your $PATH
    - Permission `chmod 755 protonhax`.

### Arch Linux
- https://aur.archlinux.org/packages/protonhax
- https://aur.archlinux.org/packages/protonhax-git/

## Debugging

Open the `protonhax` file and add to the second line
```sh
set -x
exec >/tmp/protonhax.$$.log 2>&1
```
It will save protonhax debug log into `/tmp/protonhax.*.log`

## Contributing
Contributions are always welcome! Especially if they are packages for other distributions.

## Running programs BEFORE the game.

Protonhax is not necessary, you can set your launch options to switch paths. Example:

`eval $(echo "protonhax init %command%" | sed "s|path/to/game.exe|path/to/your.exe|")`
[More](https://github.com/jcnils/protonhax/issues/5#issuecomment-2053773221)

## TODO

- [ ] Flatpak version for Steam Flatpak
- [ ] Nix Packages
- [ ] Packages for other Linux distributions.
