class Node:
	def __init__(self, data, color = "Black", left = None, right = None, parent = None):
		self.data = data
		self.color = color
		self.left = left
		self.right = right
		self.parent = parent

class RedBlackTree:
	def __init__(self):
		self.__root = Node(None, "Black")
		self.__nil = Node(None, "Black")

	def _rotateLeft(self, x):
		y = x.right
		x.right = y.left
		if y.left != self.__nil:
			y.left.parent = x
		y.parent = x.parent
		if x.parent == self.__nil:
			self.__root = y
		elif x == x.parent.left:
			x.parent.left = y
		else: 
			x.parent.right = y
		y.left = x 
		x.parent = y

	def _rotateRight(self, y):
		x = y.left
		y.left = x.right
		if x.right != self.__nil:
			x.right.parent = y
		x.parent = y.parent
		if y.parent == self.__nil:
			self.__root = x
		elif y == y.parent.right:
			y.parent.right = x
		else:
			y.parent.left = x
		x.right = y 
		y.parent = x

	def insert_fixup(self, node):
		while node.parent.color == "Red":
			if node.parent == node.parent.parent.left:
				y = node.parent.parent.right
				if y.color == "Red":
					node.parent.color = "Black"
					y.color = "Black"
					node.parent.parent.color = "Red"
					node = node.parent.parent
				elif node == node.parent.right:
					node = node.parent
					self._rotateLeft(node)
					node.parent.color = "Black"
					node.parent.parent.color = "Red"
					self._rotateRight(node.parent.parent)
			else: 
				y = node.parent.parent.left
				if  y.color == "Red":
					node.parent.color = "Black"
					y.color = "Black"
					node.parent.parent.color = "Red"
					node = node.parent.parent
				elif node == node.parent.left:
					node = node.parent
					self._rotateRight(node)
					node.parent.color = "Black"
					node.parent.parent.color = "Red"
					self._rotateLeft(node.parent.parent)
		self.__root.color = "Black"

	def insert(self, a):
		node = Node(a, "Red")
		y = self.__nil
		x = self.__root
		while x.data != None:
			y = x
			if node.data < x.data:
				x = x.left
			else:
				x = x.right
		node.parent = y
		if y.data == self.__nil:
			self.__root = node
		elif node.data < y.data:
			y.left = node
		else:
			y.right = node
		node.left = self.__nil
		node.right = self.__nil
		node.color = "Red"
		self.insert_fixup(node)

	def search(self, a):
		node = self.__root
		while node != None and node.data != a:
			if node < a:
				node = node.left
			else: 
				node = node.right	
		return node

	def getMinimum(self):
		node = self.__root
		while node.left:
			node = node.left	
		return node.data

	def getMaximum(self):
		node = self.__root
		while node.right:
			node = node.right	
		return node.data

	def successor(self, a):
		node = self.search(a)
		if node.right != self.__nil:
			return self.getMinimum()
		y = node.parent
		while y != self.__nil and node == y.right:
			node = y
			y = y.parent
		return y

	def predecessor(self, a):
		node = self.search(a)
		if node.left != self.__nil:
			return self.getMaximum()
		y = node.parent
		while y != self.__nil and node == y.left:
			node = y
			y = y.parent
		return y

	def delete_fixup(self, node):
		while node != self.root and node.color == "Black":
			if node == node.parent.left:
				w = x.parent.right
				if w.color == "Red":
					w.color = "Black"
					node.parent.color = "Red"
					self._rotateLeft(node.parent)
					w = w.node.parent.right
				if w.left.color == "Black" and w.right.color == "Black":
					w.color = "Red"
					node = node.parent
				elif w.right.color == "Black":
					w.left.color = "Black"
					w.color = "Red"
					self._rotateRight(w)
					w = node.parent.right
					w.color = node.parent.color
					node.parent.color = "Black"
					w.right.color = "Black"
					self._rotateLeft(node.parent)
					node = self.root
			else: 
				w = x.parent.left
				if w.color == "Red":
					w.color = "Black"
					node.parent.color = "Red"
					self._rotateRight(node.parent)
					w = w.node.parent.left
				if w.right.color == "Black" and w.left.color == "Black":
					w.color = "Red"
					node = node.parent
				elif w.left.color == "Black":
					w.right.color = "Black"
					w.color = "Red"
					self._rotateLeft(w)
					w = node.parent.left
					w.color = node.parent.color
					node.parent.color = "Black"
					w.left.color = "Black"
					self._rotateRight(node.parent)
					node = self.root
		node.color = "Black"

	def translate(self, u, v):
		if u.parent == self.__nil:
			self.root = v
		elif u == u.parent.left:
			u.parent.left = v
		else:
			u.parent.right = v
		v.parent = u.parent

	def deleteNode(self, a):
		node = self.search(a)
		y = node
		y_original_color = y.color
		if node.left == self.__nil:
			x = node.right
			self.translate(node, node.right)
		elif node.right == self.__nil:
			x = node.left
			self.translate(node, node.left)
		else: 
			y = self.getMinimum(node.right)
			y_original_color = y.color
			x = y.right
			if y.parent == node:
				x.parent = y
			else:
				self.translate(y, y.right)
				y.right = node.right
				y.right.parent = y
			self.translate(node, y)
			y.left = node.left
			y.left.parent = y
			y.color = node.color
		if y_original_color == "Black":
			self.delete_fixup(x)




keys = [1, 2, 3, 4, 5]
rbt = RedBlackTree()

for i in range(5):
	rbt.insert(keys[i])

print rbt.getMinimum()
print rbt.getMaximum()
print rbt.predecessor(3)
print rbt.successor(3)



