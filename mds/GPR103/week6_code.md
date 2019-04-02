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

### OfficeDelegation.cs

```cs
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class OfficeDelegation : MonoBehaviour {

    delegate void BossWork(string task);
    BossWork bossSandrasWork;

	// Use this for initialization
	void Start () {
        Debug.Log("Sandra is a very busy boss. Meanwhile, she says, her \"staff spend all day chatting and using Facebook.\"");

        Debug.Log("What are they chatting about?");

        Debug.Log("   ");
        bossSandrasWork = GeraldsTimeEnergy;
        bossSandrasWork("writing her proposals.");

        bossSandrasWork = SharmeensConstanstEfforts;
        bossSandrasWork("sheduling work for her 60 staff.");

        bossSandrasWork = MaureensEvenings;
        bossSandrasWork("ghost writing her emails.");
    }
	
    void GeraldsTimeEnergy(string task)
    {
        Debug.Log("\"Sandra drives me mental. All my time and energy is spent " + task + "\" grumbles Gerald to noone.");
    }

    protected void SharmeensConstanstEfforts(string task)
    {
        Debug.Log("\"Sandra is the worst,\" groans Sharmeen to her older colleague Maureen, \"I'm constantly " + task + "\"");
    }

    protected void MaureensEvenings(string task)
    {
        Debug.Log("\"Yeah.. One day you'll be 45, still " + task + "\" Maureen replies distantly.");
    }
}
```