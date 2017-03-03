def findsales(inpt, outpt):
	cases = int(inpt.readline())
	for i in range(1, cases+1):
		outpt.write("Case #" + str(i) + ": ")
		items = int(inpt.readline())
		prices = list(map(int, inpt.readline().split()))
		# print(prices)
		for j in range(len(prices)):
			if items == 0:
				break
			if prices[j] != 0:
				# print(prices[j])
				index = prices.index(prices[j] / .75)
				prices[index] = 0
				--items
				outpt.write(str(prices[j]) + ' ')
		outpt.write('\n')

def main():
	inpt = open("A-large-practice.in", 'r')
	outpt = open("output.txt", 'w')
	findsales(inpt, outpt)
	inpt.close()
	outpt.close()

main()