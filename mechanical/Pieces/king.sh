#!/bin/bash
set -e

cat king.svg | grep -B 1 -A 3 "style=\"fill:#" | tr -d "\n" | sed -e "s|/>|\n|g" | sed -e "s|[^f]*fill:\([^;]*\);[^=]*=\"\([^\"]*\)\".*|        <path android:fillColor=\"\1\" android:pathData=\"\2\" />|g"
