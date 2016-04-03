#ifndef CONFIG_
#define CONFIG_

#include <vector>
#include <memory>
#include "action.h"

using Actions = std::vector<std::shared_ptr<Action>>;

class Config {
 public:
  explicit Config(const std::string &);
  ~Config() = default;

  Config(const Config &) = delete;
  Config &operator=(const Config &) = delete;
  Config(Config &&) = delete;
  Config &operator=(Config &&) = delete;

  bool Initialize();

 protected:
  bool ParsePortAndProtocol(uint16_t &, std::string &);
  bool ParseActions(Actions &, std::string &);

 private:
  std::string config_name_;
  std::unordered_map<uint16_t, Actions> rules_;
};

#endif // CONFIG_
