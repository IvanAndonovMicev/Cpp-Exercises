#ifndef AdvancedInterpreter_h
#define AdvancedInterpreter_h

//#include <memory>

//#include "CalculationEngine.h"
#include "InputInterpreter.h"
#include "DivisionOperation.h"
#include "MemorySetOperation.h"
#include "MemoryReadOperation.h"

class AdvancedInterpreter : public InputInterpreter {
	std::shared_ptr<MemorySetOperation> ms;

public:

	AdvancedInterpreter(CalculationEngine& engine) : InputInterpreter(engine), ms(std::make_shared<MemorySetOperation>()) {}

	virtual std::shared_ptr<Operation> getOperation(std::string operation) {
		if (operation == "/")
			return std::make_shared<DivisionOperation>();
		else if (operation == "ms")
			return ms;
		else if (operation == "mr")
			return std::make_shared<MemoryReadOperation>(ms);
		else
			return InputInterpreter::getOperation(operation);
	}
};

#endif // !1
