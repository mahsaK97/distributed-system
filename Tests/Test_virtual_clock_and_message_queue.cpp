Test(VirtualClockTest, StartsAtZeroAndAdvance)
{
    VirtualClock clock;
    EXPECT_EQ(clock.now(), 0);
    clock.advance(150);
    EXPECT_EQ(clock.now(), 150);

}
TEST(MessageQueueTest, DeliversInTimeOrder)
{
    MessageQueue q;
    q.push(Message{/*from*/1, /*to*/2, /*deliverat*/200});
    q.psuh(Message{/*from*/3, /*to*/2, /*deliverat*/100});


auto first =q.popRaedy(/*now */150);
ASSERT_TRUE(first.has_value());
EXPECT_EQ(first->from,3);
EXPECT_FALSE(q.popReady(150).has_value());

}
