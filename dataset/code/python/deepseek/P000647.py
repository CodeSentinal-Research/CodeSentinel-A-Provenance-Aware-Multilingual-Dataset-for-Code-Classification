Here is a Python code that implements the given problem. This code uses a doubly linked list to manage a music playlist. The operations include adding a song, removing a song, playing the next song, playing the previous song, and moving a song to a specific position in the playlist.

class Node:
    def __init__(self, song):
        self.song = song
        self.prev = None
        self.next = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def addSong(self, song):
        node = Node(song)
        if self.head is None:
            self.head = node
            self.tail = node
        else:
            node.prev = self.tail
            self.tail.next = node
            self.tail = node
        self.size += 1

    def removeSong(self, song):
        node = self.head
        while node is not None:
            if node.song == song:
                if node.prev is not None:
                    node.prev.next = node.next
                else:
                    self.head = node.next
                if node.next is not None:
                    node.next.prev = node.prev
                else:
                    self.tail = node.prev
                self.size -= 1
                return
            node = node.next

    def playNext(self):
        if self.head is not None:
            next_song = self.head.song
            self.head = self.head.next
            if self.head is not None:
                self.head.prev = None
            else:
                self.tail = None
            return next_song
        return None

    def playPrevious(self):
        if self.tail is not None:
            prev_song = self.tail.song
            self.tail = self.tail.prev
            if self.tail is not None:
                self.tail.next = None
            else:
                self.head = None
            return prev_song
        return None

    def currentSong(self):
        return self.head.song if self.head is not None else None

    def moveSong(self, song, position):
        node = self.head
        index = 0
        while node is not None:
            if node.song == song:
                if position <= index:
                    node.prev.next, node.next.prev = node.next, node.prev
                    node.next = None
                    node.prev = None
                else:
                    node.prev.next, node.next.prev = node.next, node.prev
                    node.next = None
                    node.prev = None
                return
            node = node.next
            index += 1

def main():
    dl = DoublyLinkedList()

    q = int(input().strip())
    for _ in range(q):
        query = input().strip().split()

        if query[0] == 'addSong':
            dl.addSong(query[1])
            print(f'Added song {query[1]} to the playlist')
        elif query[0] == 'removeSong':
            dl.removeSong(query[1])
            print(f'Removed song {query[1]} from the playlist')
        elif query[0] == 'playNext':
            next_song = dl.playNext()
            if next_song is not None:
                print(f'Playing next song: {next_song}')
            else:
                print('No song to play next')
        elif query[0] == 'playPrevious':
            prev_song = dl.playPrevious()
            if prev_song is not None:
                print(f'Playing previous song: {prev_song}')
            else:
                print('No song to play previous')
        elif query[0] == 'currentSong':
            song = dl.currentSong()
            if song is not None:
                print(f'Current song: {song}')
            else:
                print('No song in the playlist')
        elif query[0] == 'moveSong':
            dl.moveSong(query[1], int(query[2]))
            print(f'Moved song {query[1]} to position {query[2]}')

if __name__ == "__main__":
    main()

In the main function, we get the number of operations as input. Then for each operation, we process it and print the result.

Please note that this is a simple implementation of a doubly linked list in Python, and it does not include any input handling. In a real-world application, you would want to handle errors and edge cases, such as trying to play or move a song that doesn't exist, or trying to play or move a song to an invalid position.