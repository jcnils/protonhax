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

## Installation

**protonhax** is currently a single bash script, you just need to add it to your $PATH. 

1. Either clone our repo `https://github.com/jcnils/protonhax.git`, or download the source from our [release page](https://github.com/jcnils/protonhax/releases)
2. Copy the **protonhax** file to where you preffer and give it permission to execute:
    - Example of locations `$HOME/.local/bin/protonhax`, `/usr/bin/protonhax`. They need to be on your $PATH
    - Permission `chmod 755 protonhax`.

### Arch Linux
- https://aur.archlinux.org/packages/protonhax
- https://aur.archlinux.org/packages/protonhax-git/

## Debug and Troubleshoot

### Enable *protonhax* log

Open the `protonhax` file and add to the second line
```sh
set -x
exec >/tmp/protonhax.$$.log 2>&1
```
It will save *protonhax* debug log into `/tmp/protonhax.*.log`

### $PATH

Make sure *protonhax* is in your $PATH.

Open a terminal and run `protonhax`, if you do not see instructions, go back to the installation process.

If your game does not start, make sure Steam can see and access your **$PATH**. 

Depending on how you install and execute Steam, Steam will only have access to a few locations. Like using **distrobox** or **flatpak**. Please check the issues page for `flatpak` workaround.

If your Steam is host installed,  starting  Steam from a terminal will make sure it can see your $PATH

### Steam

You can check Steam's log - location will vary depending on how you installed it (check their docs). Or start Steam from a terminal and look for the messages.

When you run *protonhax*, e.g. `protonhax cmd 12345*, you should see in the logs :

```
Adding process 44444 for gameID 12345
Adding process 44445 for gameID 12345
```

The process number will vary, and gameID will match to your game.

### Proper file path - CMD

You might be having indications that `protonhax` cannot find the program you are trying to execute. That can be an issue with file path solving. 

Try to run `protonhax cmd 12345`to confirm if it works.

If it works, you might want to try to store your program in a path with no spaces and special characters, and pass the full path to `protonhax` to make sure.

### Issues page.

You can check the issue pages for similar problems, and don't be shy to open one in case you need help troubleshooting. It always helps to make *protonhax* better.

## Contributing
Contributions are always welcome! Especially if they are packages for other distributions.

## Running programs BEFORE the game.

Protonhax is not necessary, you can set your launch options to switch paths. Example:

`eval $(echo "protonhax init %command%" | sed "s|path/to/game.exe|path/to/your.exe|")`
[More](https://github.com/jcnils/protonhax/issues/5#issuecomment-2053773221)

## Flatpak

```
mkdir -p flatpak
flatpak-builder --user --install ./flatpak/ com.valvesoftware.Steam.CompatibilityTool.protonhax.yml --force-clean
```

The script will now live in /app/share/steam/compatibilitytools.d/protonhax/

## TODO

- [ ] Nix Packages
- [ ] Packages for other Linux distributions.
- [ ] New repo for *protonhax* GUI
