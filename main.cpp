#include <iostream>
#include <string>
#include "ArtistTree.h"
#include "AlbumList.h"
#include "MusicData.h"

int main()
{
	std::cout << "Test default tree constructor." << std::endl;
	ArtistTree mytree;
	mytree.print_inorder();
	TreeNode* KM = new TreeNode("Kevin Morby");
	mytree.insert(new TreeNode("Chrome Sparks"));
	mytree.insert(new TreeNode("Kevin Morby"));
	mytree.insert(new TreeNode("Bob Moses"));
	mytree.insert(new TreeNode("Rufus Du Sol"));
	mytree.print_inorder();

	std::cout << "\n\n";

	std::cout << "Test tree construction via TreeNode." << std::endl;
	TreeNode *CS = new TreeNode("What So Not");
	ArtistTree mytree1{ CS };
	mytree1.insert(new TreeNode("Baauer"));
	mytree1.print_inorder();

	std::cout << "\n\n";

	std::cout << "Test tree construction via string and insert via string." << std::endl;
	ArtistTree mytree2{ "John Craigie" };
	mytree2.insert("The Shook Twins");
	mytree2.print_inorder();

	std::cout << "\n\n";

	std::cout << "Test AlbumList with defualt constructor." << std::endl;
	AlbumList mylist;
	mylist.print();
	ListNode *CM = new ListNode(2017, "City Music");
	mylist.add_end(CM);
	mylist.add_end(new ListNode(2018, "Solace"));
	mylist.add_end(new ListNode(2018, "Room Inside the World"));
	mylist.print();

	std::cout << "\n\n";

	std::cout << "Test AlbumList with ListNode constructor." << std::endl;
	AlbumList mylist1{ new ListNode(2018, "Scarecrow") };
	mylist1.add_end(new ListNode(2018, "Opening for Steinbeck"));
	mylist1.print();

	std::cout << "\n\n";

	std::cout << "Test AlbumList constructor and add_end with int/string argument." << std::endl;
	AlbumList mylist2{ 2018, "Not All the Beautiful Things" };
	mylist2.add_end(2018, "All Melody");
	mylist2.print();

	std::cout << "\n\n";

	std::cout << "Test MusicData constructor, add_artist, and print member functions." << std::endl;

	MusicData mymusic{ "Nils Frahm" };
	mymusic.add_artist("Dirty Projectors");
	mymusic.add_artist("Dirty Projectors");
	mymusic.print_artists();

	std::cout << "\n\n";

	std::cout << "Test MusicData add_album and print_albums member functions." << std::endl;
	MusicData mymusic1;
	mymusic1.add_album("DuRan Jones", 2018, "Duran Jones and the Indications");
	mymusic1.add_artist("Duran Jones");
	mymusic1.add_album("Duran Jones", 2018, "Duran Jones and the Indications");
	mymusic1.add_artist("DjM Trio");
	mymusic1.add_album("DJM Tri", 2018, "Cave Art Pt. 2");
	mymusic1.add_album("DjM Trio", 2018, "Cave Art Pt. 2");
	mymusic1.add_album("DjM Trio", 2014, "Cave Art");
	mymusic1.add_album("DjM Trio", 2010, "The Intrigue");
	mymusic1.print_artists();
	mymusic1.print_albums("Nils Frahm");
	mymusic1.print_albums("Duran Jones");
	mymusic1.print_albums("DjM Trio");
	
	std::cin.get();
}