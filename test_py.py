import sys
import longnumber_cpp as longnum

first.read(sys.argv[1])
second.read(sys.argv[3])

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
 
if len(sys.argv) > 4:
	module = longnum.LongNum(sys.argv[5])
	result = result % mod

result.output(sys.argv[4])
