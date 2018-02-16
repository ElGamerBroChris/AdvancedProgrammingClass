#!/usr/bin/expect -f
# For colors
proc capability cap {expr {![catch {exec tput -S << $cap}]}}
proc colorterm {} {expr {[capability setaf] && [capability setab]}}
proc tput args {exec tput -S << $args >/dev/tty}
array set color {black 0 red 1 green 2 yellow 3 blue 4 magenta 5 cyan 6 white 7}
proc foreground x {exec tput -S << "setaf $::color($x)" > /dev/tty}
proc background x {exec tput -S << "setab $::color($x)" > /dev/tty}
proc reset {} {exec tput sgr0 > /dev/tty}

#Test the program
eval spawn [lrange $argv 0 end]

#Put your test case here

send "3\r"
send "4\r"
send "100 214 120 254\r"
send "55 124 20 54\r"
send "12045 24104 12046 24106\r"
send "56 126 100 214\r"

send "5\r"
send "4141 4196 4123 4196\r"
send "761 4196 759 4196\r"
send "757 4196 760 4196\r"
send "0 4196 2 4196\r"
send "144 4196 145 4196\r"

send "4\r"
send "60 30 22 11\r"
send "214 107 256 128\r"
send "48 24 46 23\r"
send "214 107 256 128\r"

expect "No problems" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Difficult problem(s)" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
expect "Difficult problem(s)" {foreground green; puts "PASSED";reset} default {foreground red;puts "FAILED";reset}
