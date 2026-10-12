Music Playlist Manager using Doubly Linked List

1. Project Overview

The Music Playlist Manager is a menu-driven C++ application that manages songs using a Doubly Linked List. It allows users to add, delete, display, and navigate between songs.

2. Objectives

- To understand the concept of a Doubly Linked List.
- To perform insertion and deletion of songs.
- To traverse the playlist in forward and reverse directions.
- To navigate between the current, next, and previous songs.
- To handle empty playlists and boundary conditions.

3. Data Structure Used

Each node contains:

- Song title
- Artist name
- "prev" pointer to the previous node
- "next" pointer to the next node

The "head" pointer identifies the first song, while "current" identifies the currently selected song.

4. Features

1. Add Song
2. Delete Song by Title
3. Display Playlist
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit

5. Technologies Used

- Programming Language: C++
- Data Structure: Doubly Linked List
- Code Editor: Visual Studio Code
- Version Control: GitHub

6. Working Principle

The playlist is maintained using nodes connected through "prev" and "next" pointers. Songs can be traversed in both directions. The "current" pointer is updated during next and previous navigation. When a song is deleted, the links between the remaining nodes are adjusted.

7. Testing

The program is tested for:

- Empty playlist
- Adding one or multiple songs
- Forward and reverse display
- Deleting first, middle, and last songs
- Deleting a song that does not exist
- Next and previous navigation
- Boundary conditions
- Repeating the playlist

8. Screenshots

Testing screenshots are available in the "outputscreenshots" folder.

9. Conclusion

This project demonstrates the practical use of a Doubly Linked List for managing a music playlist. It helps understand node creation, pointer manipulation, traversal, deletion, and bidirectional navigation.

Author

Aditi Tambe