def f1():
	l1 = [1,2,3,4,5,6,7,8]
	l2 = []

	for n in l1:
		l2.append(n)
	print(l2)

	l3 = [n for n in l1] # list comprehension
	print(l3)

	squares = [n*n for n in l1]
	print(squares)

	#using map + lambda
	squares2 = map(lambda n:n*n, l1)
	print(squares2)

	#only even numners
	even = [n for n in l1 if n%2==0]
	print(even)

	even2 = filter(lambda n:n%2==0, l1)
	print(list(even2))

def f2():
	

if __name__ == "__main__":
	#f1()
	f2()
