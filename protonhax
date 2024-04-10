#!/bin/bash

phd=${XDG_RUNTIME_DIR:-/run/user/$UID}/protonhax

usage() {
    echo "Usage:"
    echo "protonhax init <cmd>"
    printf "\tShould only be called by Steam with \"protonhax init %%COMMAND%%\"\n"
    echo "protonhax ls"
    printf "\tLists all currently running games\n"
    echo "protonhax run <appid> <cmd>"
    printf "\tRuns <cmd> in the context of <appid> with proton\n"
    echo "protonhax cmd <appid>"
    printf "\tRuns cmd.exe in the context of <appid>\n"
    echo "protonhax exec <appid> <cmd>"
    printf "\tRuns <cmd> in the context of <appid>\n"
}

if [[ $# -lt 1 ]]; then
    usage
    exit 1
fi

c=$1
shift

if [[ "$c" == "init" ]]; then
    mkdir -p $phd/$SteamAppId
    printf "%s\n" "${@}" | grep -m 1 "/proton" > $phd/$SteamAppId/exe
    printf "%s" "$STEAM_COMPAT_DATA_PATH/pfx" > $phd/$SteamAppId/pfx
    declare -px > $phd/$SteamAppId/env
    "$@"
    ec=$?
    rm -r $phd/$SteamAppId
    exit $ec
elif [[ "$c" == "ls" ]]; then
    if [[ -d $phd ]]; then
        ls -1 $phd
    fi
elif [[ "$c" == "run" ]] || [[ "$c" == "cmd" ]] || [[ "$c" == "exec" ]]; then
    if [[ $# -lt 1 ]]; then
        usage
        exit 1
    fi
    if [[ ! -d $phd ]]; then
        printf "No app running with appid \"%s\"\n" "$1"
        exit 2
    fi
    if [[ ! -d $phd/$1 ]]; then
        printf "No app running with appid \"%s\"\n" "$1"
        exit 2
    fi
    SteamAppId=$1
    shift

    source $phd/$SteamAppId/env

    if [[ "$c" == "run" ]]; then
        if [[ $# -lt 1 ]]; then
            usage
            exit 1
        fi
        exec "$(cat $phd/$SteamAppId/exe)" run "$@"
    elif [[ "$c" == "cmd" ]]; then
        exec "$(cat $phd/$SteamAppId/exe)" run "$(cat $phd/$SteamAppId/pfx)/drive_c/windows/system32/cmd.exe"
    elif [[ "$c" == "exec" ]]; then
        if [[ $# -lt 1 ]]; then
            usage
            exit 1
        fi
        exec "$@"
    fi
else
    printf "Unknown command %s\n" "$c"
    usage
    exit 1
fi
