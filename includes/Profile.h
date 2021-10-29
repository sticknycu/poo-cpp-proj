//
// Created by NicolaeMarius.Ghergu on 10/22/2021.
//

#ifndef UTILITYIT_PROFILE_H
#define UTILITYIT_PROFILE_H

#include <iostream>
#include <utility>
#include <vector>
#include "User.h"
#include "Group.h"

class Profile: public User {
private:
    std::vector<Post> posts;
    std::vector<std::string> workList;
    std::vector<std::string> studies;
    std::vector<std::string> livingPlaces;
    std::vector<std::string> otherNames;
    std::vector<std::string> relationship;
    std::vector<std::string> family;
    std::vector<std::string> interests;
    std::vector<std::string> religion;
    std::vector<std::string> policyOrientation;
    std::vector<std::string> visits;
    std::vector<std::string> games;
    std::vector<std::string> pagesLiked;
    std::vector<User> usersFollowed;
    std::vector<std::string> events;
    long creationDate;
    std::vector<Group> groups;
    std::vector<User> followers;

public:
    Profile(std::vector<Post> posts, std::vector<std::string> workList,
            std::vector<std::string> studies, std::vector<std::string> livingPlaces,
            std::vector<std::string> otherNames, std::vector<std::string> relationship,
            std::vector<std::string> family, std::vector<std::string> interests,
            std::vector<std::string> religion, std::vector<std::string> policyOrientation,
            std::vector<std::string> visits, std::vector<std::string> games,
            std::vector<std::string> pagesLiked, std::vector<User> usersFollowed,
            std::vector<std::string> events, long creationDate, std::vector<Group> groups,
            std::vector<User> followers) : posts(std::move(posts)), workList(std::move(workList)),
                                                  studies(std::move(studies)), livingPlaces(std::move(livingPlaces)), otherNames(std::move(otherNames)),
                                                  relationship(std::move(relationship)), family(std::move(family)), interests(std::move(interests)),
                                                  religion(std::move(religion)), policyOrientation(std::move(policyOrientation)),
                                                  visits(std::move(visits)), games(std::move(games)), pagesLiked(std::move(pagesLiked)),
                                                  usersFollowed(std::move(usersFollowed)), events(std::move(events)),
                                                  creationDate(creationDate), groups(std::move(groups)), followers(std::move(followers)) {
        this->posts = posts;
        this->workList = workList;
        this->studies = studies;
        this->livingPlaces = livingPlaces;
        this->otherNames = otherNames;
        this->relationship = relationship;
        this->family = family;
        this->interests = interests;
        this->religion = religion;
        this->policyOrientation = policyOrientation;
        this->visits = visits;
        this->games = games;
        this->pagesLiked = pagesLiked;
        this->usersFollowed = usersFollowed;
        this->events = events;
        this->creationDate = creationDate;
        this->groups = groups;
        this->followers = followers;
    }

    const std::vector<Post> &getPosts() const {
        return posts;
    }

    void setPosts(const std::vector<Post> &posts) {
        this->posts = posts;
    }

    const std::vector<std::string> &getWorkList() const {
        return workList;
    }

    void setWorkList(const std::vector<std::string> &workList) {
        this->workList = workList;
    }

    const std::vector<std::string> &getStudies() const {
        return studies;
    }

    void setStudies(const std::vector<std::string> &studies) {
        this->studies = studies;
    }

    const std::vector<std::string> &getLivingPlaces() const {
        return livingPlaces;
    }

    void setLivingPlaces(const std::vector<std::string> &livingPlaces) {
        this->livingPlaces = livingPlaces;
    }

    const std::vector<std::string> &getOtherNames() const {
        return otherNames;
    }

    void setOtherNames(const std::vector<std::string> &otherNames) {
        this->otherNames = otherNames;
    }

    const std::vector<std::string> &getRelationship() const {
        return relationship;
    }

    void setRelationship(const std::vector<std::string> &relationship) {
        this->relationship = relationship;
    }

    const std::vector<std::string> &getFamily() const {
        return family;
    }

    void setFamily(const std::vector<std::string> &family) {
        this->family = family;
    }

    const std::vector<std::string> &getInterests() const {
        return interests;
    }

    void setInterests(const std::vector<std::string> &interests) {
        this->interests = interests;
    }

    const std::vector<std::string> &getReligion() const {
        return religion;
    }

    void setReligion(const std::vector<std::string> &religion) {
        this->religion = religion;
    }

    const std::vector<std::string> &getPolicyOrientation() const {
        return policyOrientation;
    }

    void setPolicyOrientation(const std::vector<std::string> &policyOrientation) {
        this->policyOrientation = policyOrientation;
    }

    const std::vector<std::string> &getVisits() const {
        return visits;
    }

    void setVisits(const std::vector<std::string> &visits) {
        this->visits = visits;
    }

    const std::vector<std::string> &getGames() const {
        return games;
    }

    void setGames(const std::vector<std::string> &games) {
        this->games = games;
    }

    const std::vector<std::string> &getPagesLiked() const {
        return pagesLiked;
    }

    void setPagesLiked(const std::vector<std::string> &pagesLiked) {
        this->pagesLiked = pagesLiked;
    }

    const std::vector<User> &getUsersFollowed() const {
        return usersFollowed;
    }

    void setUsersFollowed(const std::vector<User> &usersFollowed) {
        this->usersFollowed = usersFollowed;
    }

    const std::vector<std::string> &getEvents() const {
        return events;
    }

    void setEvents(const std::vector<std::string> &events) {
        this->events = events;
    }

    long getCreationDate() const {
        return creationDate;
    }

    void setCreationDate(long creationDate) {
        this->creationDate = creationDate;
    }

    const std::vector<Group> &getGroups() const {
        return groups;
    }

    void setGroups(const std::vector<Group> &groups) {
        this->groups = groups;
    }

    const std::vector<User> &getFollowers() const {
        return followers;
    }

    void setFollowers(const std::vector<User> &followers) {
        this->followers = followers;
    }

};

#endif //UTILITYIT_PROFILE_H
