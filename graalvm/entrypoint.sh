#!/bin/bash

set -e

export TZ="Asia/Ho_Chi_Minh"
export INTERNAL_IP="$(ip route get 1 | awk '{print $(NF-2); exit}')"

if [[ -n "${CPU_SPOOF}" ]]; then
    CPUINFO_SPOOF="/tmp/cpuinfo-spoof"
    awk '/^model name[[:space:]]*:/ { print "model name\t: " ENVIRON["CPU_SPOOF"]; next } { print }' \
        /proc/cpuinfo > "${CPUINFO_SPOOF}"
    chmod 644 "${CPUINFO_SPOOF}"
    export LD_PRELOAD="/usr/local/lib/libcpu-spoof.so${LD_PRELOAD:+:${LD_PRELOAD}}"
fi

cd /home/container || exit 1

PARSED=$(echo "${STARTUP}" | sed -e 's/{{/${/g' -e 's/}}/}/g' | eval echo "$(cat -)")
exec env ${PARSED}