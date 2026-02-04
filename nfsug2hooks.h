#include <vector>

namespace NyaHooks {
	namespace D3DEndSceneHook {
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)(void*))nullptr;
		void HookedFunction(void* a1) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1);
			for (auto& func : aFunctions) {
				func();
			}
		}
		
		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)(void*))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5D2B60, &HookedFunction);
		}
	}
	
	namespace D3DResetHook {
		std::vector<void(*)()> aFunctions;

		std::vector<void(*)()> aOrigFunctions;
		template<int T>
		void HookedFunction() {
			for (auto& func : aFunctions) {
				func();
			}
			return aOrigFunctions[T]();
		}


		void Init() {
			if (!aOrigFunctions.empty()) return;
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5D288B, &HookedFunction<0>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5D2AFF, &HookedFunction<1>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5D2BE2, &HookedFunction<2>));
		}
	}

	void PlaceD3DHooks() {
		D3DEndSceneHook::Init();
		D3DResetHook::Init();
	}

	namespace InputBlockerHook {
		bool bInputsBlocked = false;

		std::vector<void(*)()> aFunctions;

		std::vector<void(*)()> aOrigFunctions;
		template<int T>
		void HookedFunction() {
			if (bInputsBlocked) return;
			return aOrigFunctions[T]();
		}

		void Init() {
			if (!aOrigFunctions.empty()) return;
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5813AF, &HookedFunction<0>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x5813ED, &HookedFunction<1>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x581434, &HookedFunction<2>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x58146B, &HookedFunction<3>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x60A6D9, &HookedFunction<4>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x60A70F, &HookedFunction<5>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x60A73C, &HookedFunction<6>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x60A76D, &HookedFunction<7>));
			aOrigFunctions.push_back((void(*)())NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x60A791, &HookedFunction<8>));
		}
	}

	namespace WndProcHook {
		std::vector<void(*)(HWND, UINT, WPARAM, LPARAM)> aFunctions;

		auto OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))nullptr;
		LRESULT __stdcall HookedFunction(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
			for (auto& func : aFunctions) {
				func(hWnd, msg, wParam, lParam);
			}
			return OrigFunction(hWnd, msg, wParam, lParam);
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (LRESULT(__stdcall*)(HWND, UINT, WPARAM, LPARAM))(*(uintptr_t*)0x5D25A5);
			NyaHookLib::Patch(0x5D25A5, &HookedFunction);
		}
	}

	namespace WorldTimestepHook {
		std::vector<void(*)(float)> aFunctions;

		auto OrigFunction = (void(__thiscall*)(World*, float))nullptr;
		void __thiscall HookedFunction(World* a1, float a2) {
			for (auto& func : aFunctions) {
				func(a2);
			}
			return OrigFunction(a1, a2);
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(__thiscall*)(World*, float))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x581407, &HookedFunction);
		}
	}

	namespace LateInitHook {
		std::vector<void(*)()> aPreFunctions;
		std::vector<void(*)()> aFunctions;

		auto OrigFunction = (void(*)(int, char**))nullptr;
		void HookedFunction(int a1, char** a2) {
			for (auto& func : aPreFunctions) {
				func();
			}
			OrigFunction(a1, a2);
			for (auto& func : aFunctions) {
				func();
			}
		}

		void Init() {
			if (OrigFunction) return;
			OrigFunction = (void(*)(int, char**))NyaHookLib::PatchRelative(NyaHookLib::CALL, 0x580E24, &HookedFunction);
		}
	}
}