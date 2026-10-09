#!/bin/bash

read -p "Enter your commit message: " commit_msg

git add *.c
git commit -m "$commit_msg"
