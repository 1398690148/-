#!/bin/bash
if [[ $# -eq 1 ]];then
    gcc -D _DEBUG wechat.c ./common/common.c ./common/linklist.c -I ./common/ -o wechat -l pthread
else
    gcc wechat.c ./common/common.c ./common/linklist.c -I ./common/ -o wechat -l pthread
fi
