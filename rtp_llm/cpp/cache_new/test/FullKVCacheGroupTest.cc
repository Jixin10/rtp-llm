#include <gtest/gtest.h>
#include <vector>
#include <memory>
#include <thread>
#include <atomic>
#include <algorithm>
#include "rtp_llm/cpp/cache_new/FullKVCacheGroup.h"
#include "rtp_llm/cpp/cache_new/test/BlockPoolTestHelper.h"

namespace rtp_llm {
namespace test {

class FullKVCacheGroupTest: public ::testing::Test {
protected:
    void SetUp() override {}

    void TearDown() override {}
};

// ==================== 基础功能测试 ====================

TEST_F(FullKVCacheGroupTest, NeedBlocksNumTest) {
    // 测试构造函数
    auto block_pool = createBlockPool();
    block_pool->init();

    auto spec                = make_shared<MHAKVCacheSpec>();
    spec->seq_size_per_block = 4;

    FullKVCacheGroup group1({}, spec, block_pool);
    ASSERT_EQ(1, group1.needBlocksNum(10, 1));
    ASSERT_EQ(1, group1.needBlocksNum(10, 5));
    ASSERT_EQ(1, group1.needBlocksNum(1, 0));
    ASSERT_EQ(1, group1.needBlocksNum(2, 1));
}

}  // namespace test
}  // namespace rtp_llm

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
