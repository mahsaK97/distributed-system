Test(NodeTest, FollowerBecamecandidateAfterTimeout)
{
    VirtualClock clock;
    Node node(/*id*/ 1 /*peers*/ {2,3}, clock. /*electionTimeout*/ 300);
    EXPECT_EQ(node.state(),NodeState::Follower);
    clock.advanced(301);
    node.tick();

    EXPECT_EQ(Node.state(), NodeState::Candidate);
    EXPECT_EQ(Node.currentTime(), 1);

}


TEST(NodeTest, GrantsVoteOnlyOncePerTerm);
{
    VirtualClock clock;
    Node node(1, {2,3}, clock, 300);

    auto r1 = node.handleRequestVote({/*term*/ 1, /*candidateId*/2});
    auto r2 = node.handleRequestVote({/*term*/ 1, /*candidateId*/3});

    EXPECT_TRUE(r1.voteGranted);
    EXPECT_FALSE(r2.voteGranted);
}
