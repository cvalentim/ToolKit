# BASIC SIMBOLS
# . (the dot character) matches one of any characters
# * (the start character) matches zero or more of the previous character or group
# [0-9] any digit between 0 and 9. [ab] matches either a or b. [0-9a-zA-Z] matches any letter or number
# {number} will repeat the previous element the specified number of times
# ^ at the start of a range will invert the range. [^0-9] matches anything that isn't a number
# (group) the parentheses will make a group, hello{5} matches hellooooo and (hello) matches
# hellohellohellohellohello
# ^ outside of a range will match the start of a line. $ will match the end of a line.

# Ex.:
# [0-9]{3} -> matches all 3 digits numbers
# [0-9]{3}[0-9]* -> matches numbers of at least 3 digits
# [aeiou] -> matches vowels 
# [^aeiou] -> matches consonants

# ESPECIAL CHARACTERS
# \r newline 
# \n newline 
# \t tab 
# \b backspace 
# \d digit \D not a digit 
# \w word character [0-9a-zA-Z_] 
# \W not word character 
# \s whitespace character 
# \S not whitespace 
# \b when not within a range, \b refers to a word boundary character (between a word and a non-word). 
# \B is any non-boundary. 

# GREEDY x LAZY MODES
# .* -> will match the minimum number of characters that makes the whole regex works, if lazy.
# .* -> the maximum number of character in a line, if greedy
# In python, * is greedy and *? is lazy.

# LOOKAROUNDS
# foo(?=bar) positive lookahead. Will match the "foo" in "foobar" but won't match the "foo" in "foo".
# foo(?!bar) negative lookahead. Will match the "foo" in "foobaz" but won't match the "foo" in "foobar".
# (?<=bar)foo positive lookbehind. Will match the "foo" in "barfoo" but won't match the "foo" in "foo".
# (?<!bar)foo negative lookbehind. Will match the "foo" in "bazfoo" but won't match the "foo" in "barfoo".

# fooA(?!bar) -> matches fooA but not fooAbar

# Ex.:
# How to match a MAC-address? A MAC-address is a six groups of two hexadecimal digits
# ^([0-9A-F]{2}[:-]){5}([0-9A-F]{2})$
