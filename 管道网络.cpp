//
//
//����
//
//Every house in the colony has at most one pipe going into itand at most one pipe going out of it.Tanksand taps are to be installed in a manner such that every house with one outgoing pipe but no incoming pipe gets a tank installed on its roofand every house with only an incoming pipeand no outgoing pipe gets a tap.Find the efficient way for the construction of the network of pipes.
//
//����
//
//The first line contains an integer T denoting the number of test cases.For each test case, the first line contains two integer n& p denoting the number of housesand number of pipes respectively.Next, p lines contain 3 integer inputs a, b& d, d denoting the diameter of the pipe from the house a to house b.Constraints:1 <= T <= 50��1 <= n <= 20��1 <= p <= 50��1 <= a, b <= 20��1 <= d <= 100
//
//	���
//
//	For each test case, the output is the number of pairs of tanksand taps installed i.e n followed by n lines that contain three integers : house number of tank, house number of tapand the minimum diameter of pipe between them.
//
//	�������� 1
//
//	1
//	9 6
//	7 4 98
//	5 9 72
//	4 6 10
//	2 8 22
//	9 7 17
//	3 1 66
//
//	������� 1
//
//	3
//	2 8 22
//	3 1 66
//	5 6 10
//
