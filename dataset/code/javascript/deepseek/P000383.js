function findMemberByMembershipId(members, membershipId) {
  // iterate over the members array
  for(let i = 0; i < members.length; i++) {
    // if the current member's membership ID matches the given membership ID
    if(members[i].membershipId === membershipId) {
      // return the member's details
      return members[i];
    }
  }
  // if no member was found with the given membership ID, return 'Member Not Found'
  return 'Member Not Found';
}