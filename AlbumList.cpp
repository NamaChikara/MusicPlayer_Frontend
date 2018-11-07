#include "AlbumList.h"

ListNode::ListNode(int year, std::string title)
	: year{ year }, title{ title } {};

AlbumList::AlbumList() {};

AlbumList::AlbumList(ListNode *start)
	: head{ start } {};

AlbumList::AlbumList(int year, std::string album)
	: head{ new ListNode(year, album) } {}

void AlbumList::add_end(ListNode *album)
{
	// if AlbumList is empty, initialize the head
	if (!head)
	{
		head = album;
	}
	else
	{
		ListNode *temp = head;
		// navigate to the end of the list
		while (temp->next)
		{
			temp = temp->next;
		}
		// update pointers to reflect added ListNode
		temp->next = album;
		album->prev = temp;
	}
}

void AlbumList::add_end(int year, std::string album)
{
	add_end(new ListNode(year, album));
}

void AlbumList::print()
{
	if (!head)
	{
		std::cout << "Album list is empty -- nothing to print." << std::endl;
	}
	else
	{
		ListNode* temp = head;
		while (temp)
		{
			std::cout << "(" << temp->title << ", "
				<< temp->year << ")\n";
			temp = temp->next;
		}
	}
}