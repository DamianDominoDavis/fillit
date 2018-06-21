import sys
from random import choice

tetrominoes = {
	'sq': '##..\n##..\n....\n....\n',
	'lh': '####\n....\n....\n....\n',
	'lv': '#...\n#...\n#...\n#...\n',
	't1': '###.\n.#..\n....\n....\n',
	't2': '#...\n##..\n#...\n....\n',
	't3': '.#..\n###.\n....\n....\n',
	't4': '.#..\n##..\n.#..\n....\n',
	'l1': '#...\n#...\n##..\n....\n',
	'l2': '..#.\n###.\n....\n....\n',
	'l3': '##..\n.#..\n.#..\n....\n',
	'l4': '###.\n#...\n....\n....\n',
	'j1': '.#..\n.#..\n##..\n....\n',
	'j2': '###.\n..#.\n....\n....\n',
	'j3': '##..\n#...\n#...\n....\n',
	'j4': '#...\n###.\n....\n....\n',
	's1': '.##.\n##..\n....\n....\n',
	's2': '#...\n##..\n.#..\n....\n',
	'z1': '##..\n.##.\n....\n....\n',
	'z2': '.#..\n##..\n#...\n....\n'
}

num = 5 if not sys.argv else int(sys.argv[1])
with open('tet.txt', 'w') as f:
	while num > 0:
		f.write(choice(tetrominoes.values()))
		num -= 1
		if num > 0:
			f.write('\n')
	f.close()
