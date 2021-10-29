#include "Header.h"

HWND g_hWnd;
LPDIRECT3D9 g_pd3d;
LPDIRECT3DDEVICE9 g_pd3dDevice;
LPD3DXSPRITE g_Sprite;

float _elapsedTime;
DWORD _prevTime;

HRESULT InitD3D()
{
	g_pd3d = Direct3DCreate9(D3D_SDK_VERSION);
	if (g_pd3d == NULL)
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	
	if (FAILED(g_pd3d->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		g_hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&g_pd3dDevice
	)))
		return E_FAIL;

	g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, TRUE);
	D3DXCreateSprite(g_pd3dDevice, &g_Sprite);
	Init();
	return S_OK;
}

HRESULT D3DRendering()
{
	if (g_pd3dDevice == NULL)
		return E_FAIL;

	g_pd3dDevice->Clear(
		0,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(128, 128, 128),
		1.0f,
		0
	);

	if (SUCCEEDED(g_pd3dDevice->BeginScene()))
	{
		g_Sprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK);
		Render();
		g_Sprite->End();
		g_pd3dDevice->EndScene();
	}

	g_pd3dDevice->Present(NULL, NULL, NULL, NULL);

	return S_OK;
}

void CleanUp()
{
	Term();

	if (g_Sprite)
		g_Sprite->Release();

	if (g_pd3d)
		g_pd3d->Release();

	if (g_pd3dDevice)
		g_pd3dDevice->Release();
}

LRESULT WINAPI MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	MsgProc(uMsg, wParam, lParam);

	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

INT WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, INT)
{
	WNDCLASSEX wcx =
	{
		sizeof(WNDCLASSEX),
		CS_CLASSDC,
		MsgProc,
		0L,
		0L,
		GetModuleHandle(NULL),
		NULL,
		NULL,
		NULL,
		NULL,
		L"FrameWork",
		NULL
	};

	RegisterClassEx(&wcx);

	g_hWnd = CreateWindow(
		L"FrameWork",
		L"FrameWork",
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		1024,
		768,
		GetDesktopWindow(),
		NULL,
		wcx.hInstance,
		NULL
	);

	int timeCount = 0;

	if (SUCCEEDED(InitD3D()))
	{
		ShowWindow(g_hWnd, SW_SHOWDEFAULT);
		UpdateWindow(g_hWnd);
		MSG msg;
		ZeroMemory(&msg, sizeof(MSG));
		while (msg.message != WM_QUIT)
		{
			if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				DWORD curTime = timeGetTime();
				if (timeCount == 0)
				{
					timeCount = 1;
					_elapsedTime = 0;
				}
				else
					_elapsedTime = (curTime - _prevTime) / 1000.0f;
				_prevTime = curTime;

				Update(_elapsedTime);
				D3DRendering();
			}
		}
	}
	UnregisterClass(L"FrameWork", wcx.hInstance);
	return 0;
}