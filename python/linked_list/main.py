#
# Simple linked list with loose end (final node points to NULL).
# Todo:
# Add node to list (OK)
# Print list (OK)
# Remove node from list (OK)
# Count number of elements (OK)
# Sort list by id ()
#


class Ll_node:
    
    def __init__(self, id):
        self.id = id
        self.next = None
        self.sp = None

    def print(self):
        err = 0
        print(self.id, "-> ", end="")
        if (self.next == None):
            print("")            
            return err
        next = self.next
        while (next != None):
            print(next.id,"-> ", end="")
            next = next.next
        print("")
        return err
    
    def add(self, n):        
        if (n == None):
            return -1
        err = 0
        if (self.next == None):
            self.next = n
            return err
        next = self.next
        while (next.next != None):
            next = next.next
        next.next = n
        return err

    def remove(self, n):
        if (n == None):
            return -1
        err = 0
        current = self
        while (current.next != n and current.next != None):
            current = current.next
        if (current.next == None):
            err = -1
            return err
        temp = current.next
        current.next = temp.next
        temp.next = None
        return err
    
    def count(self):
        counter = 1
        if (self.next == None):
            return counter
        next = self.next
        while (next != None):
            next = next.next            
            counter = counter + 1
        return counter

def main():
    print("Hello")
    n1 = Ll_node(1)    
    n1.print()
    print(n1.count())
    n2 = Ll_node(2)
    n1.add(n2)
    n1.print()
    n3 = Ll_node(3)
    n2.add(n3)
    n1.print()
    print(n1.count())
    n1.remove(n2)
    n1.print()

if __name__=="__main__":
    main()