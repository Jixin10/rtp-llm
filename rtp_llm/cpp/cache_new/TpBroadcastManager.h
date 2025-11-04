#pragma once

#include "rtp_llm/cpp/model_rpc/RPCPool.h"

namespace rtp_llm {

class TpBroadcastHandler {
public:
    TpBroadcastHandler()          = default;
    virtual ~TpBroadcastHandler() = default;

public:
    virtual bool run(const BroadcastAllTpRequestPB& request, BroadcastAllTpResponsePB& response) = 0;
};
using TpBroadcastHandlerPtr = std::shared_ptr<TpBroadcastHandler>;

class TpBroadcastManager {
public:
    TpBroadcastManager(const std::vector<std::string>& peers): peers_(peers) {}

public:
    bool init();
    void registerHandler(const std::string& handler_name, TpBroadcastHandlerPtr handler);
    bool executeHandler(const std::string&             handler_name,
                        const BroadcastAllTpRequestPB& request,
                        BroadcastAllTpResponsePB&      response) const ;
    bool broadcast(const std::vector<BroadcastAllTpRequestPB>& requests,
                   std::vector<BroadcastAllTpResponsePB>&      responses,
                   const std::string&                          action,
                   int                                         timeout_ms) const;

private:
    std::vector<std::string>                               peers_;
    std::shared_ptr<RPCPool>                               rpc_pool_;
    std::unordered_map<std::string, TpBroadcastHandlerPtr> handlers_;
};

}  // namespace rtp_llm
