
a.out: main.o  rated_object.o Gerdabify_logic.o music.o place.o User.o  Database.o Artist.o  album.o Home.o Album_place.o admin.o Music_place.o Library.o Artist_place.o  playlist.o  Playlist_place.o single_playlist.o queue_place.o queue.o 
	g++    main.o rated_object.o Gerdabify_logic.o music.o place.o User.o Database.o Artist.o  album.o Home.o Album_place.o admin.o Music_place.o Library.o Artist_place.o playlist.o Playlist_place.o single_playlist.o queue_place.o queue.o  

main.o: main.cpp
	g++ -c main.cpp



single_playlist.o: single_playlist.h
	g++ -c single_playlist.cpp

queue_place.o: queue_place.h
	g++ -c queue_place.cpp


playlist.o: playlist.h
	g++ -c playlist.cpp

rated_object.o: rated_object.h rated_object.cpp
	g++ -c rated_object.cpp

music.o: music.h rated_object.h music.cpp
	g++ -c music.cpp

album.o: album.h rated_object.h album.cpp
	g++ -c album.cpp

place.o: place.h Gerdabify_logic.h place.cpp
	g++ -c place.cpp

Database.o: Database.h music.h Database.cpp
	g++ -c Database.cpp

Artist.o: Artist.h Database.h User.h rated_object.h Artist.cpp
	g++ -c Artist.cpp


admin.o: admin.cpp User.h rated_object.h Database.h admin.h 
	g++ -c admin.cpp

User.o: User.h playlist.h place.h User.cpp
	g++ -c User.cpp -l SDL2_mixer

queue.o: queue.h queue.cpp
	g++ -c queue.cpp -l SDL2_mixer

Gerdabify_logic.o: Gerdabify_logic.h Artist.h Gerdabify_logic.cpp
	g++ -c Gerdabify_logic.cpp



Home.o: Playlist_place.h Home.cpp
	g++ -c Home.cpp

Album_place.o: Album_place.h Album_place.cpp
	g++ -c Album_place.cpp

Music_place.o: Music_place.h Music_place.cpp
	g++ -c Music_place.cpp

Library.o: Library.h Library.cpp
	g++ -c Library.cpp

Artist_place.o: Artist_place.h Artist_place.cpp
	g++ -c Artist_place.cpp

Playlist_place.o : Playlist_place.h
	g++ -c Playlist_place.cpp


clean: 
	rm -rf *o a.out
