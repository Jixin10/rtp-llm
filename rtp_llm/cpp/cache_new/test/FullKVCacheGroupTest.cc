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

TEST_F(FullKVCacheGroupTest, AllocateTest) {
    // 测试构造函数
    // BlockPoolPtr

    // const LayerIdsType&           layer_ids,
    //                  std::shared_ptr<KVCacheSpec>  group_spec,
    //                  BlockPoolPtr                  block_pool
    auto block_pool = createBlockPool();
    block_pool->init();
    FullKVCacheGroup group1({}, nullptr, block_pool);
}

}  // namespace test
}  // namespace rtp_llm

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
