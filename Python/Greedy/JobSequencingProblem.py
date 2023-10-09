import heapq

def printJobScheduling(arr):
	n = len(arr)

	arr.sort(key=lambda x: x[1])

	result = []
	maxHeap = []

	for i in range(n - 1, -1, -1):

		if i == 0:
			slots_available = arr[i][1]
		else:
			slots_available = arr[i][1] - arr[i - 1][1]

		heapq.heappush(maxHeap, (-arr[i][2], arr[i][1], arr[i][0]))

		while slots_available and maxHeap:

			profit, deadline, job_id = heapq.heappop(maxHeap)

			slots_available -= 1

			result.append([job_id, deadline])
	result.sort(key=lambda x: x[1])

	for job in result:
		print(job[0], end=" ")
	print()

