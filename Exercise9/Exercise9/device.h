#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class device
{
public:
   device(const std::string &id): ID_(id){}

   device(const device &dev) = delete;
   device &operator=(const device &rhs) = delete;

   virtual ~device() = default;

   const std::string &getID() const { return ID_; }
   virtual void initialise()= 0;
   virtual void reset() = 0;
   virtual void shutdown() = 0;

private:
   const std::string ID_;
};

#endif // DEVICE_H
