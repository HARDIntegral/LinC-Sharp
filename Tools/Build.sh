#!/usr/bin/env bash

cd ./LinC

make build
echo ""
dotnet run ../Tests/test1.lua

