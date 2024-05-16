s = input("Do you agree? ")

s = s.lower()
if s in ['y', 'yes']:
    print('Agreed.')
elif s in ['n', 'no']:
    print('Not agreed.')
else:
    print('Type a valid letter (y or n)')
