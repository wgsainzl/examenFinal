#include <cassert>
#include "Graph.h"
#include "contentManager.h"
#include "UserManager.h"

void testAddUser() {
    UserManager userMgr;
    userMgr.addUser("user1");
    assert(userMgr.getInterests("user1").empty());
}

void testAddInterest() {
    UserManager userMgr;
    userMgr.addUser("user1");
    userMgr.addInterest("user1", "coding");
    assert(userMgr.getInterests("user1").count("coding") == 1);
}

void testAddFriendship() {
    UserManager userMgr;
    userMgr.addUser("user1");
    userMgr.addUser("user2");
    userMgr.addFriendship("user1", "user2");
    assert(userMgr.getInterests("user1").empty()); // Just to ensure no error
}

void testRemoveUser() {
    UserManager userMgr;
    userMgr.addUser("user1");
    userMgr.removeUser("user1");
    assert(userMgr.getInterests("user1").empty());
}

void testAddContent() {
    contentManager contentMgr;
    contentMgr.addContent("tech", "AI");
    assert(contentMgr.getContentByCategory("tech").size() == 1);
}

void testRecommendContent() {
    UserManager userMgr;
    userMgr.addUser("user1");
    userMgr.addUser("user2");
    userMgr.addInterest("user2", "coding");
    userMgr.addFriendship("user1", "user2");
    userMgr.recommendContent("user1"); // Just to ensure no error
}

int main() {
    testAddUser();
    testAddInterest();
    testAddFriendship();
    testRemoveUser();
    testAddContent();
    testRecommendContent();

    std::cout << "All tests passed!" << std::endl;
    return 0;
}