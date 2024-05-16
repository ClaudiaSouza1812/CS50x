text = "In the great green room"
words = text.split()

#round 1
print("Round 1")
for word in words:
    print(word)
print()

#round 2
print("Round 2")
for word in words:
    for c in word:
        print(c)
print()

#round 3
print("Round 3")
for word in words:
    if "g" in word:
        print(word)
print()

#round 4
print("Round 4")
# use slicing to skip the first two words
for word in words[2:]:
    print(word)
print()

#round 5
print("Round 5")
for _ in words:
    print("Goodnight Moon")
print()
