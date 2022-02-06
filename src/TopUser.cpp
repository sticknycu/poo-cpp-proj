//
// Created by Nicolae Marius Ghergu on 04.02.2022.
//

#include "../includes/User.h"
#include <algorithm>

int TopUser::getCountNumeric(Profile &profile) const {
    int countPosts = 0;
    std::for_each(profile.getPosts().begin(), profile.getPosts().end(),
                  [&countPosts](const std::shared_ptr<Post> post) {
                      countPosts++;
                  });
    int countFollowers = 0;
    std::for_each(profile.getFollowers().begin(), profile.getFollowers().end(),
                  [&countFollowers](const std::shared_ptr<User> follower) {
                      countFollowers++;
                  });
    return countFollowers - countPosts;
}

void TopUser::setCountNumeric(int countNumeric_) {
    TopUser::countNumeric = countNumeric_;
}

TopUser::TopUser(int countNumeric_) {
    this->countNumeric = countNumeric_;
}

TopUser::TopUser(const User &copie, int countNumeric) : User(copie), countNumeric(countNumeric) {}

TopUser::~TopUser() {

}
