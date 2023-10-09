
def printMaxActivities(s, f):
	n = len(f)
	print("Following activities are selected")

	i = 0
	print(i, end=' ')

	for j in range(1, n):

		if s[j] >= f[i]:
			print(j, end=' ')
			i = j
