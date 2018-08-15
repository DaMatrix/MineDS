#!/bin/bash

if [ -d "/run/user/1000/gvfs/sftp:host=192.168.1.112,user=pi/home/pi/ds-store-1.0-SNAPSHOT" ];
then
    cp ./MineDS.nds "/run/user/1000/gvfs/sftp:host=192.168.1.112,user=pi/home/pi/ds-store-1.0-SNAPSHOT/games/MineDS.nds";
    OLD_INC_COUNTER=$( cat "/run/user/1000/gvfs/sftp:host=192.168.1.112,user=pi/home/pi/ds-store-1.0-SNAPSHOT/info/MineDS.nds.info");
    echo "$(( $OLD_INC_COUNTER + 1 ))" > "/run/user/1000/gvfs/sftp:host=192.168.1.112,user=pi/home/pi/ds-store-1.0-SNAPSHOT/info/MineDS.nds.info";
    echo "$(( $OLD_INC_COUNTER + 1 ))";
    echo Copied ROM to store;
else
    echo Not copying ROM to SD card;
fi
