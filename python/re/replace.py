#! /usr/bin/env python
# A program demonstrating regular expressions in Python
# taken from http://openclassroom.stanford.edu/MainFolder/VideoPage.php?course=PracticalUnix&video=grep3&speed=100
import re

#Some names
search_me = ["Sam King (Mr.)", "Kawa Kuller (Mrs.)", "Sam J J King"]

# A line that has one word, a space, a second word, a space,
# and a third word inside parentheses. Each word has a group
# Uses a r' string to avoid Python escaping "\" since we want 
# the regular expression engine to capture them. Equivalent to:
# find_pattern = "^([^ ]*) ([^ ]*) \\(([^)]*)\\)$"
find_pattern = r'^([^ ]*) ([^ ]*) \(([^)]*)\)$'

# Replace "Sam King (Mr. )" with "Mr. King, Sam"
replace_pattern = r'\3 \2, \1'

for name in search_me:
	print name
	print "turns into"
	print re.sub(find_pattern, replace_pattern, name)
print

# Replace "Sam J J King" with "Sam King"
# (?: ) is a group that doesn't count in the group's counting
# -> passive group
find_pattern = r'([^ ]*)(?: [A-Z]){2} (.*)'
replace_pattern = r'\1 \2'
for name in search_me:
	print name
	print "turns into"
	print re.sub(find_pattern, replace_pattern, name)
print
