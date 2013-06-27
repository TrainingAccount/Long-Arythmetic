import sys
import longnumber_cpp as longnum

if len(sys.argv) < 5:
	print 'Invalid parameters; try again, friend'
	
else:

	first = longnum.LongNum(sys.argv[1])
	second = longnum.LongNum(sys.argv[3])

	selector = sys.argv[2]
	if selector == "+":
		result = first + second
	elif selector == "-":
		result = first - second
	elif selector == "*":	
		result = first * second
	elif selector == "/":
		result = first / second
	elif selector == "%":
		result = first % second
	elif selector == "^":
		result = first ^ second
 
	if len(sys.argv) > 5:
		module = longnum.LongNum(sys.argv[5])
		result = result % mod

	result.toFile(sys.argv[4])
