# Week 6 Code


## Events Etc

### TriggerMoveEventOnClick.cs

```cs
using System;
using System.Collections.Generic;
using UnityEngine;

public class TriggerMoveEventOnClick : MonoBehaviour {
	public static event Action<string> OnMoveRequested = delegate {};
	
	public string wayToMove = "no_event";

	private void OnMouseUpAsButton() {
		Debug.Log("up!");
		// generate an event using the eventToThrow string
		OnMoveRequested(wayToMove);
		
	}
}
```

### KeyMover.cs

```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class KeyMover : MonoBehaviour {
	
    private void Awake()
    {

    }

    void Start() {
        // Set up initial unlocked state

        // Register with TriggerMoveEventOnClick that we'd like to be 
        // notified of any OnMoveRequested if it has any events. We give it
        // the local function we would like to run when it happens.
        TriggerMoveEventOnClick.OnMoveRequested += MoveRequestedHandler;
	}

    // Define the function we'd like to handle any OnMoveRequested events
    private void MoveRequestedHandler(String wayToMove)
    {
       
            switch (wayToMove)
            {
                case "up":
                    transform.position += transform.up;
                    break;
                case "down":
                    transform.position -= transform.up;
                    break;
            }
    }
	
	
	// Update is called once per frame
	
	private void OnDestroy() {
		TriggerMoveEventOnClick.OnMoveRequested -= MoveRequestedHandler;
	}
}

```
## Office Delegation

Class